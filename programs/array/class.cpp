#include <iostream>
using namespace std;

class Shape {
        public:
                float width;
                float height;
                virtual float getarea() { return 0.0; }; 
};

class Circle: public Shape {
        public:
                Circle(float radius);
                float getarea() ; 
};

class Rectangle: public Shape {
        public:
                Rectangle(float width, float height);
                float getarea() ; 
};

class Square: public Rectangle {
        public:
                Square(float size); 
};


Circle::Circle ( float radius) {

   width = radius;
}

Rectangle::Rectangle(float wid, float hgt) {

    width = wid;
    height = hgt;
}

Square::Square(float size) {

    width = size; 
    height = size;
}
float Circle::getarea() {

    return 3.14159265*width*width;
}

float Rectangle::getarea() {

return width*height;
}

/*float Square::getarea() {
 
return width*width;
  
} */



int main (int argc, char **argv) {

        Shape * shapes[5];
    
        float radius, width, height;
        
        cin >> radius ;
        Circle C1(radius);
        
        cin >> width >> height ;
        Rectangle R1(width, height);
    
        cin >> radius ;
        Circle C2(radius);
    
        cin >> width; 
        Square S1(width);
        
        cin >> width >> height ;
        Rectangle R2(width, height);

        shapes[0] = &C1; shapes[1] = &R1; shapes[2] = &C2;
        shapes[3] = &S1; shapes[4] = &R2;

        for (int k=0; k<5; k++) {
                cout << "Area is " << shapes[k]->getarea() << endl;
        }

        return 0;
}
