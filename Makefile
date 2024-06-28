# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall -g

# Archivos fuente
SOURCES =  main.cpp GreenHouse.cpp AlarmSensors.cpp UsersServer.cpp MonitoringSystem.cpp AirQualitySensor.cpp Hardware.cpp HydrometerSensor.cpp KeyboardHardware.cpp LightSensor.cpp TemperatureSensor.cpp UserAdmin.cpp UserGuest.cpp UserEmployee.cpp User.cpp PhSensor.cpp PressureSensor.cpp ScreenHardware.cpp Sensor.cpp SwitchHardware.cpp UsersDatabase.cpp

# Archivos objeto generados
OBJECTS = $(SOURCES:.cpp=.o)

# Nombre del ejecutable
EXECUTABLE = main

# Regla de compilación
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regla de compilación de objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para formatear archivos
format:
	find . -name "*.cpp" -o -name "*.h" | xargs clang-format -i

# Limpiar archivos generados
clean:
	rm -r -f $(EXECUTABLE) $(OBJECTS)
