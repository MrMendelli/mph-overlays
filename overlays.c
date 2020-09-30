#include <stdio.h>

#define NUM_OVERLAYS	18

const char overlay_ids[NUM_OVERLAYS] = {
	4, 6, 0x11, 5, 0x10, 0, 7, 1, 2, 3, 8, 0xF, 0xA, 9,
	0xB, 0xC, 0xD, 0xE
};

const char* overlay_names[NUM_OVERLAYS] = {
	/* 00 */ "Multiplayer: WFC",
	/* 01 */ "Multiplayer: Wireless Download Play",
	/* 02 */ NULL,
	/* 03 */ "Multiplayer: Voice Chat",
	/* 04 */ NULL,
	/* 05 */ "Frontend",
	/* 06 */ NULL,
	/* 07 */ "Movies",
	/* 08 */ "Common: Models/FX",
	/* 09 */ "Contains an entity type",
	/* 10 */ "Common: Pause Screen, Nav Screen, Camera Sequences, Artifacts",
	/* 11 */ "Single Player: portals, room loading, platforms, objects, force fields",
	/* 12 */ "Single Player: room transition code, gorea",
	/* 13 */ "Single Player: room transition code, Multiplayer: CTF/Nodes",
	/* 14 */ "Boss: Alimbic Turret, Cylinder Boss",
	/* 15 */ "Boss: Gorea",
	/* 16 */ "Boss: Big Eye",
	/* 17 */ NULL,
};

int main(int argc, char** argv)
{
	if(argc != 2) {
		printf("usage: %s overlay-word\n"
				"\n"
				"The overlay word can be found at 0x020EB650\n",
				*argv);
		return 1;
	}

	int active_overlay_map;
	sscanf(argv[1], "%x", &active_overlay_map);

	for(int i = 0; i < NUM_OVERLAYS; i++) {
		if(active_overlay_map & (1 << i)) {
			if(overlay_names[i]) {
				printf("overlay %02d [ROM:%02d] is loaded [%s]\n",
						i, overlay_ids[i],
						overlay_names[i]);
			} else {
				printf("overlay %02d [ROM:%02d] is loaded\n",
						i, overlay_ids[i]);
			}

		}
	}
}
