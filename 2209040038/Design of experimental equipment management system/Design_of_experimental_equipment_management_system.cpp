#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char type[50];
    char name[50];
    double price;
    char purchaseDate[20];
    int isScrapped;
    char scrappedDate[20];
} Device;

Device devices[100]; 
int count = 0; 


void displayMenu();
void addDevice();
void modifyDevice();
void classifyDevices();
void processDamagedDevices();
void searchDevice();

int main() {
    int choice;

 
    while (1) {
        displayMenu();
        printf("������ѡ��");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDevice();
                break;
            case 2:
                modifyDevice();
                break;
            case 3:
                classifyDevices();
                break;
            case 4:
                processDamagedDevices();
                break;
            case 5:
                searchDevice();
                break;
            case 0:
                printf("��лʹ��ʵ���豸����ϵͳ��\n");
                exit(0);
            default:
                printf("��Ч��ѡ�����������롣\n");
        }
    }
    return 0;
}


void displayMenu() {
    printf("\n************* ʵ���豸����ϵͳ *************\n");
    printf("1. ¼���豸��Ϣ\n");
    printf("2. �޸��豸��Ϣ\n");
    printf("3. �豸����ͳ��\n");
    printf("4. �豸����ķѺ�������\n");
    printf("5. ��ѯ�豸\n");
    printf("0. �˳�ϵͳ\n");
    printf("*******************************************\n");
}


void addDevice() {
    if (count >= 100) {
        printf("�豸�����Ѵ����ޣ��޷�¼������豸��\n");
        return;
    }

    Device device;
    printf("�������豸��ţ�");
    scanf("%d", &device.id);
    printf("�������豸���ࣺ");
    scanf("%s", device.type);
    printf("�������豸���ƣ�");
    scanf("%s", device.name);
    printf("�������豸�۸�");
    scanf("%lf", &device.price);
    printf("�������豸�������ڣ�");
    scanf("%s", device.purchaseDate);
    printf("���豸�Ƿ񱨷ϣ�1-�ǣ�0-�񣩣�");
    scanf("%d", &device.isScrapped);
    if (device.isScrapped == 1) {
        printf("�������豸�������ڣ�");
        scanf("%s", device.scrappedDate);
    }

    devices[count++] = device;
    printf("�豸¼��ɹ���\n");
}


void modifyDevice() {
    int id;
    int i;
    int found = 0;

    printf("������Ҫ�޸ĵ��豸��ţ�");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (devices[i].id == id) {
            Device device;

            printf("�������豸���ࣺ");
            scanf("%s", device.type);
            printf("�������豸���ƣ�");
            scanf("%s", device.name);
            printf("�������豸�۸�");
            scanf("%lf", &device.price);
            printf("�������豸�������ڣ�");
            scanf("%s", device.purchaseDate);
            printf("���豸�Ƿ񱨷ϣ�1-�ǣ�0-�񣩣�");
            scanf("%d", &device.isScrapped);
            if (device.isScrapped == 1) {
                printf("�������豸�������ڣ�");
                scanf("%s", device.scrappedDate);
            }

            devices[i] = device;
            found = 1;
            printf("�豸��Ϣ�޸ĳɹ���\n");
            break;
        }
    }

    if (!found) {
        printf("δ�ҵ��豸���Ϊ%d���豸��\n", id);
    }
}

void classifyDevices() {
    int i;
    int computerCount = 0;
    int printerCount = 0;
    int scannerCount = 0;
    int otherCount = 0;

    for (i = 0; i < count; i++) {
        if (strcmp(devices[i].type, "΢��") == 0) {
            computerCount++;
        } else if (strcmp(devices[i].type, "��ӡ��") == 0) {
            printerCount++;
        } else if (strcmp(devices[i].type, "ɨ����") == 0) {
            scannerCount++;
        } else {
            otherCount++;
        }
    }

    printf("�豸����ͳ�ƽ����\n");
    printf("΢����%d̨\n", computerCount);
    printf("��ӡ����%d̨\n", printerCount);
    printf("ɨ���ǣ�%d̨\n", scannerCount);
    printf("�����豸��%d̨\n", otherCount);
}


void processDamagedDevices() {
    int id;
    int i;
    int found = 0;

    printf("������Ҫ������豸��ţ�");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (devices[i].id == id) {
            if (devices[i].isScrapped == 1) {
                printf("�豸�ѱ��ϡ�\n");
            } else {
                devices[i].isScrapped = 1;
                printf("�������豸�������ڣ�");
                scanf("%s", devices[i].scrappedDate);
                printf("�豸���ϴ���ɹ���\n");
                found = 1;
            }
            break;
        }
    }

    if (!found) {
        printf("δ�ҵ��豸���Ϊ%d���豸��\n", id);
    }
}


void searchDevice() {
    int id;
    int i;
    int found = 0;

    printf("������Ҫ��ѯ���豸��ţ�");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (devices[i].id == id) {
            printf("�豸��ţ�%d\n", devices[i].id);
            printf("�豸���ࣺ%s\n", devices[i].type);
            printf("�豸���ƣ�%s\n", devices[i].name);
            printf("�豸�۸�%.2lf\n", devices[i].price);
            printf("�豸�������ڣ�%s\n", devices[i].purchaseDate);
            if (devices[i].isScrapped == 1) {
                printf("�豸�������ڣ�%s\n", devices[i].scrappedDate);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("δ�ҵ��豸���Ϊ%d���豸��\n", id);
    }
}
