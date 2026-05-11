#include "studio.h"
#include "defs.h"

int main() {

	AllInit();

	for (index = 0; index < BRD_SQ_NUM; ++index) {
		if (index % 10 == 0) printf("\n");
		printf("%d", Sq120ToSq64[index]);
	}

	printf("\n");
	printf("\n");

	for (index = 0; index < 64; ++index) {
		if (index % 8 == 0) printf("\n");
		printf("%d", Sq64ToSq120[index]);
	}

	return 0;
}