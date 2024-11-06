float temperature_readings[30][24];

float total_temp = 0;
for (int month = 0; month < 30; ++month) {
    for (int hour = 0; hour < 24; ++hour) {
        total_temp += temperature_readings[month][hour];
    }
}
float avg_temp = total_temp/(30.0f*24.0f);