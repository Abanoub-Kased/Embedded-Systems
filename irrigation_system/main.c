
#include "./Application/APP_interface.h"

int main(void)
{
	irrigation_init('D', 5, 'A', 1, 'A', 0);
	display_init('B', 'A', 6, 7);
	soil_t soilStatus;
	temp_t tempStatus;
	while(1)
	{	
		soilStatus = SoilMoisture();
		tempStatus = AirTempearture();
			
		if(soilStatus==DRY){
			display_status("long time");	
			WaterPumpDuration(LONG);
		}
		else if(soilStatus==MOIST && (tempStatus==NORMAL || tempStatus==HEAT)){
			display_status("medium time");
			WaterPumpDuration(MEDIUM);
		}
		else if ((soilStatus==MOIST && tempStatus==COLD)||(soilStatus==WET && tempStatus==HEAT)){
			display_status("short time");
			WaterPumpDuration(SHORT);
		}
		else{
			display_status("OFF");
			WaterPumpDuration(OFF);		
		}
    }
}
