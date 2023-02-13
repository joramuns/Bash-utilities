# LinuxMonitoring v2.0

## Part 9. Bonus. Your own node_exporter

##### Change the **Prometheus** configuration file so it collects information from the page you created.

- Add folder ```/metrics``` to nginx configuration file;
- Add new job to prometheus linked to nginx web server.

##### Run the same tests as in Part 7

![part1.1](img/ex02_test.png "Test part 2")
`Test metrics with script from part 2`

![part1.2](img/ex03_test.png "Test part 3")
`Test metrics with script from part 3`


![part2.1](img/stress_test.png "Junk filesystem test")
`System load after running stress utility`
