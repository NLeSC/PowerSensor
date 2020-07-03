//  Copyright (C) 2016
//  ASTRON (Netherlands Institute for Radio Astronomy) / John W. Romein
//  P.O. Box 2, 7990 AA  Dwingeloo, the Netherlands

//  This file is part of PowerSensor.

//  PowerSensor is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  PowerSensor is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with PowerSensor.  If not, see <http://www.gnu.org/licenses/>.


#include "PowerSensor.h"

#include <iostream>

#include <inttypes.h>
#include <unistd.h>

#define MAX_MICRO_SECONDS 4000000


void usage(char *argv[])
{
  std::cerr << "usage: " << argv[0] << " [-d device] [-f dump_file] [-s sensor]" << std::endl;
  exit(1);
}


int main(int argc, char *argv[])
{
  const char *device = "/dev/ttyACM1", *dumpFileName = "output.txt";

  PowerSensor::PowerSensor powerSensor(device);
  //powerSensor.writeSensorsToEEPROM()
  powerSensor.dump(dumpFileName);

  usleep(100000);
  
  return 0;
}
