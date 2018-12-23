#define Assert(x) Test(x)
#define _CRT_SECURE_NO_WARNINGS
#define SWEET_NOCOLOUR
#include <sweet/sweet.h>
#include "alloc.h"
#include <omp.h>

int main()
{
	TestGroup("Allocation")
	{
		TestGroup("Pool")
		{

		}

		TestGroup("Buddy")
		{

		}

		TestGroup("Stack/Arena")
		{
			pal_memory testMem = {0};
			pal_stack_push_size(&testMem, 43, 0);
			TestVEq(testMem.stack[0].len, 43, %zd");
			TestOp(testMem.stack[0].len, 43);
		}
	}

	return PrintTestResults(sweetPAUSE_FAIL);

	{
		test_t *val = pal_stack_push_size(palPermanent, 8*sizeof(*vals), 0);
		*val = myTestVal;
	}

#pragma omp for
	for(int i = 0; i < AL_NUM_UNIQUE_THREADS; ++i)
	{
		int iThrd = omp_get_thread_num();
		test_t *vals1 = pal_stack_push_size(palPermanent, 8*sizeof(*vals), iThrd);
		test_t *vals2 = pal_stack_push_struct(palFrame, test_t, iThrd);
		pal_stack_push_structs_scope(test_t, vals3, 7, iThrd)
		{

		} // vals3 no longer valid; len retracted
	}
}
