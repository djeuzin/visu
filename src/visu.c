#include "visu.h"

int to_sort[LEN];
char stage_name[1024];

void draw_frame(int *v, int a, int b) {
    system("clear");

    printf("%s\n", stage_name);

    for(int i=0; i<LEN; i++) {
        printf("            ");
        for(int j=0; j<LEN; j++) {
            if(v[j] <= LEN-1-i) 
                printf("  ");
            else{
                if(j == a || j == b)
                    set_foreground(RED);
                printf("# ");
                set_foreground(WHITE);
            }
        }

        printf("\n");
    }

    #ifdef _WIN32
    Sleep(SLEEP_TIME_WIN);
    #else
    usleep(SLEEP_TIME_UNIX);
    #endif
}

void swap(int* v, int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
    draw_frame(v, i, j);
}

void shuffle(int *v) {
	strcpy(stage_name, "Embaralhando");
    for(int i=0; i<30; i++) {
        int j = rand()%30;
        swap(v, i, j);
    }
}

void init_window(void) {
	#ifdef WIN32
	system("mode con: cols=80 lines=25");
	#else
	system("resize -s 40 80");
	#endif

	system("clear");

	for(int i=0; i<LEN; i++)
		to_sort[i] = i+1;
}

void visu(void (*sorting_function)(int*, int), char* name) {
	init_window();

	shuffle(to_sort);
	
	strcpy(stage_name, name);
	
	sorting_function(to_sort, LEN);
	
	strcpy(stage_name, "Terminado");
	
	draw_frame(to_sort, -1, -1);
}