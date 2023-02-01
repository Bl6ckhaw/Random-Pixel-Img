#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main()
{
    image img1 = init(3000,3000);
    save(img1, "test.ppm");

    return 0;
}
