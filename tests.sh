if [ "$(echo "echo a && exit" | ./a.out)" = "$( echo a && exit)" ]; then
echo "OK!"
else
echo "Fail!"
fi;
if [ "$(echo "echo a && exit" | ./a.out)" = "$( echo a && exit)" ]; then
echo "OK!"
else
echo "Fail!"
fi;
if [ "$(echo "              echo a&&echo b&&exit                   " | ./a.out)" = "$(            echo a&&echo b && exit                  )" ]; then
echo "OK!"
else
echo "Fail!"
fi;