#include <stdio.h>

int main()
{
    int sa, sb;
    printf("Inform the size of the first list: ");
    scanf("%d", &sa);
    int ma[sa];
    printf("Inform the size of the second list: ");
    scanf("%d", &sb);
    int mb[sb];
    printf("Inform the list of integers space separated:\n");
    for (int i = 0; i < sa; i++) {
        scanf("%d", &ma[i]);
    }
    printf("Inform the list of integers space separated:\n");
    for (int i = 0; i < sb; i++) {
        scanf("%d", &mb[i]);
    }

    printf("Intersection between first and second list:\n");
    for (int i = 0; i < sa; i++) {
        for (int j = 0; j < sb; j++) {
            if (ma[i] == mb[j]) {
                printf("%d ", ma[i]);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}
