// #include <iostream>


#define MAX(a,b) (a > b ? a : b)

#define SQR(x) ((x) * (x))
int LogAndReturn(int x) {
    cout << "x = " << x << endl;
    return x;
}

int main(){
    int x = LogAndReturn(3);
    int y = 1;
    int z = SQR(x++);
}