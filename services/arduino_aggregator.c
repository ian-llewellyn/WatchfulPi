/*
 * Multiple sensors in
 * Single JSON transmitted out
 */

setup() {

}

loop() {
    // Measure Oil Level
    oil_level = hcsr04.get_distance()

    // Measure Temperature
    temp = bmp180.get_temperature()

    // Measure Pressure
    pressure = bmp180.get_presure(temp)

    // Battery Voltage
    voltage = arduino.get_voltage()



    // Create JSON Message
    json = """
{"measurements": [{
    "id": oil_level.id,
    "reading": oil_level.value
},{
    "id": temp.id,
    "reading": temp.value
},{
    "id": pressure.id,
    "reading": pressure.value
},{
    "id": voltage.id,
    "reading": voltage.value
}]}
    """

    // Transmit JSON Message
    for (i=0; i<6; i++) {
        txrx433.transmit(json);
        sleep(1);
    }

    // Sleep
    sleep(53);
}
