while (true)
do
    info_path="/var/www/html/metrics/data.html"
    cpu_load=$(ps -eo pcpu | awk '{sum+=$1} END{print $sum}')
    free_space=$(df -m / | tail -1 | awk '{print $4}')
    free_ram=$(free -m | awk '/Mem/ {print $4}')
    echo "# HELP s21_cpu_load CPU usage" > $info_path
    echo "# TYPE s21_cpu_load gauge" >> $info_path
    echo "s21_cpu_load $cpu_load" >> $info_path
    echo "# HELP s21_free_space Free space" >> $info_path
    echo "# TYPE s21_free_space gauge" >> $info_path
    echo "s21_free_space $free_space" >> $info_path
    echo "# HELP s21_ram_available RAM Available" >> $info_path
    echo "# TYPE s21_ram_available gauge" >> $info_path
    echo "s21_ram_available $free_ram" >> $info_path
    sleep 3
done
