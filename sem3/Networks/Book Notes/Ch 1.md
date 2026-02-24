Cable Internet access :
- shared broadcast medium => every packet sent by the head end travels downstream on every link to every home & every packet sent by a home travels on the upstream channel to the head end 
- Consequence: if several users are simultaneously downloading a file , the rate at which each user receives it will be lower than the aggregate cable downstream rate

Types of residential broadband access:
1) DSL (Digital subscriber line) 
2) Cable
3) FTTH (Fiber to the home)

DSL, Cable -> copper wire
HFC (Hybrid fiber-coaxial) -> fiber & coaxial cables
Mobile access -> radio spectrum

FTTH : 
-> Several competing technologies for optical distr. from CO to the homes. Simplest : direct fiber (One fiber leaving the CO for each home). More common: each fiber leaving the CO is actually shared by many homes, when it gets close to the home it is split. 
- 2 Competing optical distribution architectures that perform said splitting: AON and PON . (active / passive optical networks)

PON:
Each home has: 
- *ONT ( optical network terminator)* connected by a dedicated optical fiber to a **neighbourhood splitter**. The splitter combines, usually, less than 100 homes onto a single optical fiber. This connects to an *OLT (Optical line terminator)* .
- Users connect a home router (typically wireless) to the ONT and access the internet via this router. 
	
The telco's CO has: 
- OLT - it provides conversion between optical and electrical signals and connects to the internet via a telco router. 
-> All packets sent from the OLT to the splitter are replicated at the splitter ( send to each ONT )


LANs:
-> many types of LAN technologies - ethernet is the most prevalent
-> Ethernet users use **twisted pair copper wire** to connect to an Ethernet switch. This switch is then connected to the larger internet. 

2 types of mediums:
- guided ( cables, fiber ) 
- unguided (radio channels terrestrial/satellite)


<mark style="background: #D2B3FFA6;">Twisted-Pair Copper Wire</mark> 
-> least expensive ; most commonly used 
-> Consists of 2 insulated copper wires, each about 1 mm thick , arranged in a spiral pattern. They are twisted to reduce electrical interference from similar pairs close by.
-> Unshielded twisted pair (UTP) is commonly used for LANs. (10 Mbps / 10 Gbps)
-> data rates depend on : wire thickness, distance between transmitter-receiver
![[Pasted image 20260206082127.png]]

<mark style="background: #D2B3FFA6;">Coaxial Cable</mark> 
-> 2 copper conductors, concentric.
-> high transmission rates
-> common in cable television systems 
-> can be used as a **guided shared medium** - a number of end systems can be connected directly to the cable, with each of the end systems receiving whatever is sent by the other end systems.
![[Pasted image 20260206082201.png]]


<mark style="background: #D2B3FFA6;">Fiber Optics</mark>
-> Thin, flexible , conducts pulses of light (each pulse represents a bit). 
-> A single optical fiber can support up to hundreds of gigabits/sec. 
-> immune to electromagnetic interference, low signal attenuation up to 100 km, hard to tap.
-> preferred especially for overseas links.
-> high cost of optical devices (transmitters ,receivers & switches) => not used for short-haul transport

![[Pasted image 20260206083045.png]]


<mark style="background: #D2B3FFA6;">Terrestrial Radio Channels</mark>
-> carry signals in the electromagnetic spectrum
-> Considerations: path loss, shadow fading, multi-path fading and interference
-> Can be classified in 3 groups:
- Very short distance ( 1-2 m )
- in LANs
- in WANs 

<mark style="background: #D2B3FFA6;">Satellite Radio Channels</mark>
-> A communication satellite links 2+ Earth microwave transmitter / receivers (ground stations). 
-> The satellite receives transmissions on one frequency band, regenerates the signal using a **repeater** and transmits the signal on *another frequency*.
-> 2 types:
- Geostationary satellites:
  -> permanently remain above the same spot on Earth. Planted in orbit at 36,000 km above Earth's surface. Propagation delay - 280 ms.
- Low-earth orbiting (LEO) satellites:
  -> closer to Earth. They rotate and may communicate with each other + ground stations.


# 1.3 Network Core

Packet Switching
-> End systems exchange messages. The source breaks long messages into smaller chunks of data = **Packets.** 
-> Each packet travels through communication links and **packet switches.** (routers and link-layer switches).
-> Packets are transmitted over each communication link at a rate equal to the *full transmission rate* of the link.


<mark style="background: #ADCCFFA6;">Store & Forward:</mark>
-> packet switch must receive the entire packet before it can begin to transmit the first bit of the packet onto the outbound link.
N * L/R (ignoring propagation delay)




