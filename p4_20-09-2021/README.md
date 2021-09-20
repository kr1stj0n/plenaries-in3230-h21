# 4th plenary session: 20.09.2021 #

Since the deadline of the Oblig is approaching (Friday September 24, 23:59), in
this plenary session we focused on some small, but yet important pieces of the
whole Oblig, specifically on preparing a simple hello packet with its own hello
header and sending / receiving it via RAW sockets. We had a live-coding session
where we constructed the packet (frame header + hello header + SDU data) at the
sender side and decoded it at the receiver side.

Check the code [here](https://github.com/kr1stj0n/plenaries-in3230-h21/tree/main/p4_20-09-2021/ping-pong)
and feel free to adapt it for the Oblig.  

**NOTE:** These examples that we are coding in the plenaries are very simple,
and do not follow the best coding practises. Most of the time we hardcode stuff
for the sake of simplicity.
Make sure to write clean and efficient code in C, with proper functions and
better comments.  

In this session we used sendmsg / recvmsg to send the data encapsulated in a msg
header. Another path that you can follow while working with the Oblig is to
serialize / deserialize structure inside byte arrays. We didn't have time to
talk about this, but feel free to explore more this approach on your own.  

Here is a good start:  
<https://www.includehelp.com/c/how-to-copy-complete-structure-in-a-byte-array-character-buffer-in-c%20language.aspx>
