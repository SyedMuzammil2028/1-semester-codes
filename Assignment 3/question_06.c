#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float temp;
    float rain;
    float wind;
} Weather;

typedef struct
{
    char cropType[50];
    int growth;
    float yield;
    Weather *forecast;
} Crop;

typedef struct
{
    char toolName[50];
    char status[20];
    float fuel;
    char schedule[100];
} Equipment;

typedef struct
{
    float nutrients;
    float ph;
    int pests;
} Sensor;

typedef struct
{
    float lat;
    float lon;
    char soil[20];
    float moisture;
    int cropCount;
    Crop *crops;
    int equipCount;
    Equipment *tools;
    int sensorCount;
    Sensor *sensors;
} Field;

typedef struct
{
    char hubName[50];
    int fieldCount;
    Field *fields;
} RegionalHub;

typedef struct
{
    int hubCount;
    RegionalHub *hubs;
} AnalyticsServer;

Field createField(float lat, float lon, const char *soil, float moisture)
{
    Field f;
    f.lat = lat;
    f.lon = lon;
    strcpy(f.soil, soil);
    f.moisture = moisture;
    f.cropCount = 0;
    f.crops = NULL;
    f.equipCount = 0;
    f.tools = NULL;
    f.sensorCount = 0;
    f.sensors = NULL;
    return f;
}

void addCrops(Field *f, int count)
{
    f->cropCount = count;
    f->crops = (Crop *)malloc(count * sizeof(Crop));
    for (int i = 0; i < count; i++)
    {
        scanf("%s %d %f", f->crops[i].cropType, &f->crops[i].growth, &f->crops[i].yield);
        f->crops[i].forecast = (Weather *)malloc(sizeof(Weather));
        scanf("%f %f %f", &f->crops[i].forecast->temp, &f->crops[i].forecast->rain, &f->crops[i].forecast->wind);
    }
}
void addEquipment(Field *f, int count)
{
    f->equipCount = count;
    f->tools = (Equipment *)malloc(count * sizeof(Equipment));
    for (int i = 0; i < count; i++)
    {
        scanf("%s %s %f %s", f->tools[i].toolName, f->tools[i].status, &f->tools[i].fuel, f->tools[i].schedule);
    }
}

void addSensors(Field *f, int count)
{
    f->sensorCount = count;
    f->sensors = (Sensor *)malloc(count * sizeof(Sensor));
    for (int i = 0; i < count; i++)
    {
        scanf("%f %f %d", &f->sensors[i].nutrients, &f->sensors[i].ph, &f->sensors[i].pests);
    }
}

RegionalHub createHub(const char *name, int count)
{
    RegionalHub hub;
    strcpy(hub.hubName, name);
    hub.fieldCount = count;
    hub.fields = (Field *)malloc(count * sizeof(Field));
    return hub;
}
void freeField(Field *f)
{
    for (int i = 0; i < f->cropCount; i++)
    {
        free(f->crops[i].forecast);
    }
    free(f->crops);
    free(f->tools);
    free(f->sensors);
}

void freeHub(RegionalHub *hub)
{
    for (int i = 0; i < hub->fieldCount; i++)
    {
        freeField(&hub->fields[i]);
    }
    free(hub->fields);
}

int main()
{
    AnalyticsServer server;
    server.hubCount = 1;
    server.hubs = (RegionalHub *)malloc(server.hubCount * sizeof(RegionalHub));
    server.hubs[0] = createHub("Region1", 1);
    server.hubs[0].fields[0] = createField(12.34, 56.78, "Good", 45.0);
    addCrops(&server.hubs[0].fields[0], 2);
    addEquipment(&server.hubs[0].fields[0], 2);
    addSensors(&server.hubs[0].fields[0], 2);
    freeHub(&server.hubs[0]);
    free(server.hubs);
    return 0;
}