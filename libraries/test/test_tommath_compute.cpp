#include "testingsetup.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <boost/test/unit_test.hpp>
#include "../libtommath/tommath.h"

BOOST_FIXTURE_TEST_SUITE(tommath_compute,TestingSetup)

int myrng(unsigned char *dst, int len, void *dat)
{
	int x;
	for (x = 0; x < len; x++) dst[x] = rand() & 0xFF;
	return len;
}

//得到lon比特长素数
int GetPrime(mp_int *m,int lon)
{
	int rand_flag = rand()&1;
	printf("rand falg is: %d",rand_flag);
	int flag = (rand_flag)?0x0004:LTM_PRIME_2MSB_ON;

	int ret = mp_prime_random_ex(m, 10, lon,flag, myrng, NULL);
 // mp_prime_random_ex(m, 10, lon,LTM_PRIME_2MSB_ON, myrng, NULL);
	return ret;
}

BOOST_AUTO_TEST_CASE(prime_test)
{
	std::cout << "This is  prime test!" <<  std::endl;
	std::cout << "begin -------------------" << std::endl;

	mp_int prime1;
	mp_init(&prime1);
	GetPrime(&prime1,80);

	char prime1_show[800]={0};
	printf("the value of prime1 is :\n");
	mp_toradix(&prime1,prime1_show,10);	
	printf("%s\n",prime1_show);

	mp_clear(&prime1);

	mp_int prime2;
	mp_init(&prime2);
	GetPrime(&prime2,80);
	char prime2_show[800]={0};
	printf("the value of prime2 is : \n");
	mp_toradix(&prime2,prime2_show,10);
	printf("%s\n",prime2_show);
	

	mp_clear(&prime2);
					

	std::cout << "end ---------------------" << std::endl;
}

BOOST_AUTO_TEST_CASE(c_test)
{
	printf("This is C io test!\n");
	printf("begin ------------------------\n");
	printf("end --------------------------\n");

}

BOOST_AUTO_TEST_SUITE_END()
