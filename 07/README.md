# LinuxMonitoring v2.0

## Part 7. **Prometheus** and **Grafana**


##### Install and configure **Prometheus** and **Grafana** in virtual machine

- sudo apt install prometheus

- sudo snap install grafana

##### Access the **Prometheus** and **Grafana** web interfaces from a local machine

![part1.1](img/prometheus_web.png "Prometheus web interface")
`Prometheus web interface on localhost:3044 forwarded from 9090 port`

![part1.2](img/grafana_web.png "Grafana web interface")
`Grafana web interface on localhost:3055 forwarded from 3000 port`

##### Add to the **Grafana** dashboard a display of CPU, available RAM, free space and the number of I/O operations on the hard disk.

- CPU usage:
    - avg(irate(node_cpu_seconds_total{mode!='idle'}[1m]))

- RAM available:
    - node_memory_MemAvailable_bytes/(1024^2)

- Free space:
    - node_filesystem_avail_bytes{device="/dev/mapper/ubuntu--vg-ubuntu--lv"}/(1024^3)

- Disk I/O usage:
    - sum(rate(node_disk_writes_completed_total[1m]))
    - sum(rate(node_disk_reads_completed_total[1m]))

![part2](img/dashboards.png "Dashboard with panels")
`All required panels on dashboard`

##### Run your bash script from Part 2

![part3.1](img/run_script_ex02.png "Run script from part 2")
`Make some junk on filesystem`

![part3.2](img/clean_ex02.png "Clean junk")
`Run cleaning script from part 3`

##### Check the hard disk load (disk space and read/write operations)

![part4.1](img/stat_after_ex02.png "Dashboard after script")
`System load after running script from part 2`

![part4.2](img/after_clean_ex02.png "Dashboard after clean")
`System load after cleaning by script from part 3`

##### Install the **stress** utility and run the following command `stress -c 2 -i 1 -m 1 --vm-bytes 32M -t 10s`
- sudo apt install stress
- stress -c 2 -i 1 -m 1 --vm-bytes 32M -t 10s

![part5](img/stress_test.png "Run stress utility")
`Executing the given example with longer time in order to see the result on dashboard better`

##### Check the hard disk, RAM and CPU load

![part6](img/result_stress_test.png "System load with stress utility")
`System load after running stress utility`
