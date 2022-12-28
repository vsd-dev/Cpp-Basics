#include<iostream>

int main()
{
struct {
	std::string brand;
	std::string model;
	int year;	
} car1, car2;

car1.brand = "Tesla";
car1.model = "Model 1";
car1.year = 2020;

#define MAX_TRACKS 5
#define SOCKET_SEND 1
car2.brand = "Tesla";
car2.model = "Model 3";
car2.year = 2022;

#ifdef SOCKET_SEND
	std::cout << "Car " << car1.brand << car1.model << " " << car1.year << std::endl;
	std::cout << "Car " << car2.brand << car2.model << " " << car2.year << std::endl;
#endif

struct Points{
	int x1;
	int y1;
	int x2;
	int y2;
} points1;

typedef struct track_map_s {
	int id;
	struct Points p[MAX_TRACKS];
} track_map_t;

points1.x1 = 10;
points1.y1 = 30;

track_map_t maps[5];
maps[0].id = 1;
maps[0].p[0].x1 = 10;
maps[0].p[0].y1 = 40;
std::cout << "points1 " << points1.x1 << " " << points1.y1 << " " << maps[0].p[0].x1 << " " << std::endl;
return 0;

}
