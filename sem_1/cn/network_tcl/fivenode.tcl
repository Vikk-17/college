set ns [new Simulator]
set nf [open fivenode.nam w]
set tf [open fivenode.tr w]

$ns trace-all $tf
$ns namtrace-all $nf

proc finish {} {
  global ns nf tf
  $ns flush-trace
  exec nam fivenode.nam &
  close $nf
  close $tf
  exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

$ns color 1 "Red"
$ns color 2 "Blue"

$n0 label "Sourcr/TCP"
$n1 label "Sourc/UDP"
$n2 label "Destination/NULL"
$n3 label "Destination/TCPSink"
$n4 label "Router"

$ns duplex-link $n0 $n4 1mb 10ms DropTail
$ns duplex-link $n1 $n4 1mb 10ms DropTail
$ns duplex-link $n4 $n2 1mb 10ms DropTail
$ns duplex-link $n4 $n3 1mb 10ms DropTail

set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp

set ftp [new Application/FTP]
$ftp attach-agent $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink

$ns connect $tcp $sink

set udp [new Agent/UDP]
$udp set class_ 1
$ns attach-agent $n1 $udp

set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 500
$cbr set interval_ 0.005
$cbr attach-agent $udp

set null [new Agent/Null]
$ns attach-agent $n2 $null

$ns connect $udp $null

$ns at 0.0 "$ftp start"
$ns at 0.0 "$cbr start"
$ns at 9.0 "$ftp stop"
$ns at 9.0 "$cbr stop"
$ns at 10.0 "finish"
$ns run
