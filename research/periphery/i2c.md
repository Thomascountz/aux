# Inter-Integrated Circuit Communication Bus

I2C (or I²C) is a communication protocol for integrated circuits, namely microprocessors. It's an alternative to SPI (Serial Peripheral Interface) and UART (Universal Asynchronous Receiver Transmitter) protocols.

The core benefit of I2C is that is allows for many "follower" components to bidirectionally communication to a main "leader" component with only 2 logic wires, VCC, and ground. A leader initiates communication to a specific follower by sending out the follower's address. If the follower hears its address, it acknowledges that it is ready to send or receive data.

## Physical Bus

The two logic wires are SCL, serial clock line used to synchronize the devices communicated with each other, and SDA, serial data line. These two lines are connected to all of the devices on the I2C bus. Both SCL and SDA are open drain drivers, which means that devices communicating on the bus can drive the lines to logic low through a common ground line. Therefore, the two data lines must be pulled to a logic high by using pull-up resistors.

![](/research/periphery/images/i2c_circuit.png)

## Leaders & Followers

Devices on the I2C bus are either **leaders** or **followers**.

The **leader** device drives the SCL (clock line), which initiates the transmission of data across the SDA (data line) bidirectionally: either from the leader to the follower or from the follower to the leader. This means that a **follower** device cannot initiate communication across the bus.

**Old Terminology** — In antiquated texts and diagrams, you may see leader devices referred to as *"masters"* and follower devices referred to as *"slaves."*

There are often many followers connected to an I2C bus, but most often only one leader. It is possible to configure a bus to have multiple leaders. In this scenario, only one leader can control the SCL (clock line) at a time.

**Multi-Leader I2C** — ****At the time of writing, I have not come into a situation that has called for using multiple leaders on an I2C bus, therefore, I have not researched this configuration at length.

## Physical Protocol

Communication across the bus begins when the leader sends out a **start sequence**, which followed by an **address frame**. Once acknowledged, then comes one ore more 8-bit **data frames** (which are each followed by an **acknowledgement bit**). Finally the communication concludes with the leader sending a **stop sequence**.

![](/research/periphery/images/i2c_sequence.png)

source: Sparkfun electronics

### Start Sequence

The start sequence happens when the leader is ready to send or request data on the bus. To do this, the master pulls SDA (data line) low while SCL (clock line) remains high. The start and stop sequence are the only times when SDA changes while SCL is high.

### Address Frame

Leaders must know the addresses of followers in order to communicate with them. The address frame follows immediately after the start sequence, and contains 9 bits: the first seven bits are used for the follower's **7-bit address** with the [most significant bit](/research/periphery/most_significant_bit.md) (MSB) first, and the eighth bit is the **read/write bit** and is is used to indicate whether the leader will **read** (`1`) or **write** (`0`). The ninth and final bit of the address frame is the **ACK/NACK bit** (acknowledge/negative acknowledge).

This ACK/NACK happens on the ninth clock pulse when control over SDA (data line) is given to the receiver, in this case, the follower with the address transmitted in the address frame. To acknowledge that the follower is ready, it pulls SDA (data line) low. If on the ninth clock pulse SDA (data line) is still high, it is assumed that the receiving device either did not receive the data or did not know how to parse the message. In this case, it is up to the leader to recover.

### Data Frame

After the start sequence, address frame, and acknowledgement, **data frames** can begin to be transmitted over SDA (data line), again with the [most significant bit](/research/periphery/most_significant_bit.md) first. The leader will continue control over the SCL (clock line), and either the leader or follower will transmit 8 bits of data on SDA depending on the read/write bit in the address frame. The number of frames is dictated by the size of the message being transmitted.

After each 8-bit frame, a ninth bit, again, represents an ACK/NACK. This is controlled by the receiver, which can either be the follower, when in write mode, or the leader, when in read mode.

### Stop Sequence

After all of the data frames are transmitted, the leader will generate a stop sequence by **allowing SDA (data line) to go high *while* SCL (clock line) is high**. During data transmission, SDA (data line) does not change while SCL (clock line) is high.

## Resources

- [https://www.robot-electronics.co.uk/i2c-tutorial](https://www.robot-electronics.co.uk/i2c-tutorial)
- [https://learn.sparkfun.com/tutorials/i2c/all](https://learn.sparkfun.com/tutorials/i2c/all)