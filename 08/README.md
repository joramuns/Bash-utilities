# LinuxMonitoring v2.0

## Part 8. A ready-made dashboard

##### Download the ready-made dashboard *Node Exporter Quickstart and Dashboard* from **Grafana Labs** official website.

![part1.1](img/download.png "Grafana official site")
`Just click copy Dashboard ID`

![part1.2](img/import_grafana.png "Import menu in grafana")
`Import menu in grafana and paste Dashboard ID`

##### Run the same tests as in [Part 7](#part-7-prometheus-and-grafana)

![part2.1](img/ex_02_check.png "Junk filesystem test")
`Run script from Part 2 and look at dashboard`

![part2.2](img/ex_03_check.png "Clean filesystem test")
`Run script from Part 3 to clean filesystem and check the dashboard`

##### Start another virtual machine within the same network as the current one
##### Run a network load test using **iperf3**

![part3](img/iperf3_server.png "Start listening iperf3")
`Output of iperf3 server side while measuring speed`

##### Check the network interface load

![part4](img/iperf3_network_usage.png "Grafana output")
`Grafana output of network usage`
