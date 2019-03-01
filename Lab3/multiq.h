#include<stdio.h>
#include "que.h"

typedef Node* Task;

typedef Queue* Multi;

Multi* createMQ(int num);

Multi* addMQ(Multi *m, Task t);

Task* nextMQ(Multi *m);

Task* delNextMQ(Multi *m);

Task* isEmptyMQ(Multi *m);

int sizeMQ(Multi *m);

int sizeByPriority(Multi *m, int p);

Queue* getQueueFromMQ(Multi *m, int p);
