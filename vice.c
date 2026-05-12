#include "studio.h"
#include "defs.h"


int main() {

	AllInit();

	S_BOARD pos[1];
	S_SEARCHINFO info[1];
	info->quit = FALSE;
	info->threadNum = 1;
	HashTable->pTable = NULL;
	InitHashTable(HashTable, 64);
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	//TempHashTest(PERFT);
	//TempHashTest(WAC1);
	//exit(0);


	int ArgNum = 0;

	for (ArgNum = 0; ArgNum < argc; ++ArgNum) {
		if (strncmp(argv[ArgNum], "NoBook", 6) == 0) {
			EngineOptions->UseBook = FALSE;
			printf("Book Off\n");
		}
	}

	printf("Welcome to Vice! Type 'vice' for console mode...\n");

	char line[256];
	while (TRUE) {
		memset(&line[0], 0, sizeof(line));

		fflush(stdout);
		if (!fgets(line, 256, stdin))
			continue;
		if (line[0] == '\n')
			continue;
		if (!strncmp(line, "uci", 3)) {
			Uci_Loop(pos, info);
			if (info->quit == TRUE) break;
			continue;
		}
		else if (!strncmp(line, "quit", 4)) {
			break;
		}
	}

	free(HashTable->pTable);
	CleanPolyBook();
	return 0;
}