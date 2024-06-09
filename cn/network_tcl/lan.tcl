# Simulate to study transmissions of packets over ethernet lan and determine
# the number of packets drop destination.

set ns [new Simulator]
set nf [open lan.nam w]
set tf [open lan.tr w]

$ns trace-all $tf
$ns namtrace-all $nf

proc finish {} {
  global ns nf tf
  $ns flush-trace
  exec nam lan.nam &
  close $nf
  close $tf
  exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]

$ns make-lan "$n0 $n1 $n2 $n3 $n4 $n5 $n6" 100mb 1ms LL Queue/DropTail
Mac/802_3 ChannelPhy/WiredPhy

# set tcp0 at n0 with packetSize_ 1000 and window_ 8000
# set tcp1 at n2 with same
set tcp0 [new Agent/TCP]
$tcp0 set packetSize_ 1000
$tcp0 set window_ 8000
$ns attach-agent $n0 $tcp0

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

set tcp1 [new Agent/TCP]
$tcp1 set packetSize_ 1000
$tcp1 set window_ 8000
$ns attach-agent $n2 $tcp1

set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1

set sink0 [new Agent/TCPSink]
$ns attach-agent $n6 $sink0
$ns connect $tcp0 $sink0

set sink1 [new Agent/TCPSink]
$ns attach-agent $n5 $sink1
$ns connect $tcp1 $sink1

$ns at 0.0 "$ftp0 start"
$ns at 0.0 "$ftp1 start"
$ns at 24.0 "$ftp0 stop"
$ns at 24.0 "$ftp1 stop"
$ns at 25.0 "finish"
$ns run

