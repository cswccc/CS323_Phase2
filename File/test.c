struct people{
    int name;
    int age;
    int salary;
};

struct plepeo{
    int didi;
    int gege;
    int baba;
    int mama;
};

int test(struct people p1,struct plepeo p9){
    int re=p1.age+p9.gege;
    return re;
}
int main(){
    struct people p;
    struct plepeo p5;
    p.age=5;
    p5.gege = 10;
    int b=test(p,p5);
    write(b);
    return 0;
}
