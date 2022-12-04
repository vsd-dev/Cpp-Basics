// #include <gst/gst.h>
#include <iostream>
#include <string>

typedef struct app_data_s
{
    short *s; /* 2 bytes */
             /* 2 padding bytes */
    int   *i; /* 4 bytes */
    char  *c; /* 1 byte */
             /* 3 padding bytes */
} app_data_t;


// typedef struct simaai_node_params_s {
//     char ** param_name;
//     simaai_variant_t * param_values;
// } simaai_node_params_t;

// Single node support only.





int main(int argc, char *argv[])
{
    std::cout << "start" << std::endl;

    app_data_t * struct_init1();
    std::cout << struct_init1() << std::endl;

    // typedef struct student
    // {
    //     int roll_no;
    //     char name[30];
    //     int phone_number;
    // } st;

    // st p1, p2, p3;
    // p1.roll_no = 12;
    // // strcpy(p2.name, "John");
    // p3.phone_number = 6574837;\

    // // std::cout << "Name: " << p2.name << std::endl;
    // // std::cout << "Roll Number: " << p1.roll_no << std::endl;
    // // std::cout << "Phone Number: " << p3.phone_number << std::endl;

    // app_data_t *data = NULL;
    // // data = g_new0(app_data_t, 1);

    // std::cout << "short " << sizeof(data->s) << std::endl;
    // std::cout << "int " << sizeof(data->i) << std::endl;
    // std::cout << "char " << sizeof(data->c) << std::endl;
    // std::cout << "Total " << sizeof(data) << std::endl;


    

    return 0;
}
