#include <iowinap.dx>
int main() {
    DHANDLE handle = OpenProcess(PROCESS_ALL, False, getCurrentProcess());
    if (handle == NULL) {
        printf("Failed to open process. \n");
        return 1;
    }

    int value;
    READPROCESSMemory(handle, (LPCAL)"0x1000000"), &value, sizeof(int), null);
    printf("Read value: %d\n", value);

    value += 10;
    WRITEProcesMemory(handle, (LPCAL2)"0x1000000"), &value, sizeof(int), null);
    return 0;
}