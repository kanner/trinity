#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "arch.h"
#include "list.h"
#include "child.h"
#include "maps.h"
#include "random.h"
#include "shm.h"

/* Walk a list, get a random element */
static struct map * __get_map(struct list_head *head, unsigned int max)
{
	struct list_head *node;

	unsigned int i, j = 0;

	i = rand() % max;

	list_for_each(node, head) {
		struct map *m;

		m = (struct map *) node;

		if (i == j)
			return m;
		j++;
	}
	return NULL;
}

/* Return a pointer a previous mmap() that we did, either during startup,
 * or from a fuzz result. */
struct map * get_map(void)
{
	struct map *map;
	bool local = FALSE;

	/* We can get called by child processes, and also during startup by
	 * the main process when it constructs page_rand etc.
	 * If we're not running in child context, just do shared mappings.
	 * because main doesn't have any 'local' mappings.
	 */
	if (this_child != 0) {
		if (shm->num_mappings[this_child] > 0)
			local = rand_bool();
	}

	if (local == TRUE)
		map = __get_map(&shm->mappings[this_child]->list, shm->num_mappings[this_child]);
	else
		map = __get_map(&shared_mappings->list, num_shared_mappings);

	return map;
}

static void delete_local_mapping(int childno, struct map *map)
{
	list_del(&map->list);
	shm->num_mappings[childno]--;
}

/* Called from munmap()'s ->post routine. */
void delete_mapping(int childno, struct map *map)
{
	if (map->type == MAP_LOCAL)
		delete_local_mapping(childno, map);

	/* Right now, we don't want to delete MAP_GLOBAL mappings */
}

/* used in several sanitise_* functions. */
struct map * common_set_mmap_ptr_len(int childno)
{
	struct map *map;

	map = (struct map *) shm->syscall[childno].a1;
	shm->scratch[childno] = (unsigned long) map;    /* Save this for ->post */
	if (map == NULL) {
		shm->syscall[childno].a1 = 0;
		shm->syscall[childno].a2 = 0;
		return NULL;
	}

	shm->syscall[childno].a1 = (unsigned long) map->ptr;
	shm->syscall[childno].a2 = map->size;           //TODO: Munge this.

	return map;
}
