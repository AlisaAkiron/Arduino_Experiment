import matplotlib.pyplot as plt
import numpy as np

import asyncio
import datetime
import serial

# Change those values in your need
fig_save_path = "/Users/liamsho/figs"
servial_port = "/dev/cu.usbserial-140"
serial_baudrate = 9600

ser = serial.Serial(servial_port, serial_baudrate)

angle = []
distance = []


def calc_theta(degree):
    return degree / 180 * np.pi


async def read_serial():
    while True:
        # Use pySerial to read the value of the serial port
        data = ser.readline()
        str = ''.join(map(chr, data)).replace('\n', '').replace('\r', '')

        # Get angle and distance
        splited = str.split('.')

        print("Currnet: ", splited[0], " - ", splited[1])

        # One scan is ended, wait 0.1 second and let the image be saved
        if(int(splited[0]) == 500):
            angle.clear()
            distance.clear()
            await asyncio.sleep(0.1)
            continue

        # Add angle and distance to list
        angle.append(calc_theta(int(splited[0])))
        distance.append(int(splited[1]))

        await asyncio.sleep(0.0001)


async def paint():
    while True:

        # Save the image while angle list have 181 elements, which is the max element count
        if len(angle) == 181:
            name = fig_save_path + "/fig" + datetime.datetime.now().strftime("%X") + ".png"
            plt.savefig(name)

        # Interactive plot
        plt.clf()
        ax = plt.gca(projection='polar')
        ax.set_thetagrids(np.arange(0.0, 360.0, 15.0))
        ax.set_thetamin(0.0)
        ax.set_thetamax(180.0)
        ax.set_rgrids(np.arange(0, 80.0, 20.0))
        ax.set_rlabel_position(0.0)
        ax.set_rlim(0.0, 80.0)
        ax.set_axisbelow('True')
        plt.scatter(angle, distance, s=5, c='red')
        plt.pause(0.001)
        plt.ion()

        await asyncio.sleep(0.0001)

# Run both async functions at the same time and wait them
coroutine_1 = read_serial()
coroutine_2 = paint()
loop = asyncio.get_event_loop()
task = loop.create_task(coroutine_1)
task = loop.create_task(coroutine_2)
loop.run_until_complete(task)
