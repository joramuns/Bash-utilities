#!/usr/bin/awk -f

# BEGIN {
#     FS="\n";
#     }
#     {
#         ARRAY[$var] = $R;
#         }
#         END {
#             asorti(ARRAY,SARRAY);
#             j = length(SARRAY);

#             for (i = 1; i <= j; i++) {
#                 printf("%s\n", SARRAY[i])
#                 }
#             }
# BEGIN {
#     FS="\n";
#            }
#            {
#                array[NR]=$1
#                print array[NR]
#            }
#            END {
#                # for (i = 0; i < 3)
#            }


{a[$6]=$0} 
END {
    PROCINFO["sorted_in"] = "@ind_num_asc"; 
    for(i in a) {
        print a[i]
    }
}


awk '{if ($6 ~ "[45]..") {print $0}}'
