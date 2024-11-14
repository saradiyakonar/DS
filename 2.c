#include <stdio.h>

struct Distance {
    int km;
    int meter;
};

struct Distance addDistances(struct Distance d1, struct Distance d2) {
    struct Distance result;

    result.km = d1.km + d2.km;
    result.meter = d1.meter + d2.meter;

    if (result.meter >= 1000) {
        result.km += result.meter / 1000;
        result.meter %= 1000;
    }

    return result;
}

int main() {
    struct Distance distance1, distance2, sumDistance;

    printf("Enter the first distance in km and meter: ");
    scanf("%d %d", &distance1.km, &distance1.meter);

    printf("Enter the second distance in km and meter: ");
    scanf("%d %d", &distance2.km, &distance2.meter);

    sumDistance = addDistances(distance1, distance2);

    printf("Sum of distances: %d km %d meter\n", sumDistance.km, sumDistance.meter);

    return 0;
}