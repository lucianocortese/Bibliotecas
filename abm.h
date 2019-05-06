typedef struct{//eFecha
    int dia;
    int mes;
    int anio;
   }eFecha;
typedef struct{//eEmpleados
    int legajo;
    char vNombre[51];
    char vApellido [51];
    char sexo;
    float sueldo;
    eFecha alta;
    int idSector;
    int isEmpty;
}eEmpleados;
typedef struct{//eSector
    int id;
    char vDescripcion[51];
}eSector;//Hardcodear
typedef struct{//eMenu
    int codigo;
    char vDescripcion[51];
    float importe;
}eMenu;
typedef struct{//eAlmuerzo
    int legajoEmp;
    int codigoMenu;
    eFecha fechaAlm;
    int isEmpty;
}eAlmuerzo;

void mostrarEmpleado (eEmpleados lista[], int ind, eSector sectores[]);
void mostrarEmpleados (eEmpleados lista[], int tam, eSector sectores[]);
void inicializarEmpleados (eEmpleados lista[], int tam);
int buscarvacio (eEmpleados lista[], int tam);
int altaEmpleado (eEmpleados lista [], int tam, int contLegajo);
void bajaEmpleado (eEmpleados lista[], int tam, eSector sectores[]);
int buscarEmpleado (eEmpleados lista[], int tam, int leg);
void ordenarPorApellido(eEmpleados lista[], int tam);
void modificarEmpleado (eEmpleados lista[], int tam, eSector sectores[]);
void hardcodeo (eEmpleados lista[], int tamEmpl, eSector sectores[], int tamSect, eMenu carta[], int tamMenu);
void inicializarAlmuerzo (eAlmuerzo almuerzos[], int tamAlm);
int buscarAlmLibre (eAlmuerzo almuerzos[], int tamAlm);
void altaAlmuerzo (eEmpleados emp[],eSector sec[], eMenu carta[], int tamMenu, eAlmuerzo almuerzos[], int tamAlm);
void mostrarAlmuerzo(eEmpleados emp[], eSector sec[], eMenu carta[], eAlmuerzo almuerzos[], int tamAlm);
