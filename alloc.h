/* TODO
 * ====
 * - rename to `pal` - P___ ALlocator
 *   - personal
 *   - parallel
 *   - ...
 *
 * - split by timeframe
 *   - do you want all of them to have the same available timeframes?
 *
 * - default alloc/dealloc/realloc of any sig on 0
 * - otherwise use included function with included opaque data
 */

#ifndef AL_MAX_UNIQUE_THREADS
#define AL_MAX_UNIQUE_THREADS 8
#endif/*AL_MAX_UNIQUE_THREADS*/

#define PAL_ERRORS(F) \
	F(Ok) \
	F(OutOfMemory) \
	F(InvalidInput) \

#define PAL_ENUM(v) pal_Err_## v,
#define PAL_STR(v) #v,

typedef enum pal_err { PAL_ERRORS(PAL_ENUM) pal_Err_Count } pal_err;
char const * const pal_errStrs[] = { PAL_ERRORS(PAL_STR) };

typedef union al_u_mem {
	void *base;
	char *bytes;
} al_u_mem;

typedef struct al_stack
{
	size_t len, cap;
	al_u_mem mem;
} al_stack;


typedef struct al_pool_block {
	al_u_mem mem;
} al_pool_block;

typedef struct al_pool
{
	size_t cBlocks;
	size_t const blockSize;
	al_pool_block *pool;
} al_pool;

typedef struct al_buddy
{
	size_t cBuddies;
	size_t const minBuddySize;

	// TODO
} al_buddy;

typedef struct pal_memory
{
	al_stack stack[AL_MAX_UNIQUE_THREADS], // aka arena
	         stackAll;
	al_pool  pool [AL_MAX_UNIQUE_THREADS], // not visible across threads, requires no synchronization
		     poolAll;                      // visible across threads, requires synchronization
	al_buddy buddy[AL_MAX_UNIQUE_THREADS],
		     buddyAll;

	void *(*   allocate)(size_t);
	void *(* reallocate)(size_t, void *);
	void  (* deallocate)(void *);
} pal_memory;

#ifndef PAL_NO_GLOBALS
pal_memory palPermanent_, palFrame_, palScope_, palScratch_;
pal_memory * const palPermanent = palPermanent_,
					  * const palFrame     = palFrame_,
					  * const palScope     = palScope_,
					  * const palScratch   = palScratch_;
#endif/*PAL_NO_GLOBALS*/


#ifndef ALLOC_H

al

#define ALLOC_H
#endif//ALLOC_H
