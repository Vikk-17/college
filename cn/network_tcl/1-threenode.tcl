set ns [new Simulator]
set nf [open 1-threenode.nam w]
set tf [open 1-threenode.tr w]

$ns trace-all $tf
$ns namtrace-all $nf

proc finish {} {
  global ns nf tf
  $ns flush-trace
  exec nam 1-threenode.nam &
  close $nf
  close $tf
  exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns color 1 "Red"
$ns color 2 "Blue"

$n0 label "Source/UDP"
$n1 label "Source/UDP"
$n2 label "Router"
$n3 label "Destination/NULL"

$ns duplex-link $n0 $n2 100mb 300ms DropTail
$ns duplex-link $n1 $n2 100mb 300ms DropTail
$ns duplex-link $n2 $n3 1mb 300ms DropTail

$ns set queue-limit $n0 $n2 50
$ns set queue-limit $n1 $n2 50
$ns set queue-limit $n2 $n3 5

set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

set udp1 [new Agent/UDP]
$udp1 set class_ 2
$ns attach-agent $n1 $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetSize_ 500
$cbr1 set interval_ 0.005
$cbr1 attach-agent $udp1

set null [new Agent/Null]
$ns attach-agent $n3 $null
$ns connect $udp0 $null
$ns connect $udp1 $null


$ns at 0.5 "$cbr0 start"
$ns at 1.0 "$cbr1 start"
$ns at 4.0 "$cbr0 stop"
$ns at 4.5 "$cbr1 stop"
$ns at 5.0 "finish"
$ns run
