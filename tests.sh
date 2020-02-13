gcc template.c -o template

if [ "$(echo "echo a && exit" | ./template)" = "$( echo a && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a"
fi;

if [ "$(echo "echo a b c && exit" | ./template)" = "$( echo a b c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a b c"
fi;

#if [ "$(echo "\n && exit" | ./template)" = "$( \n && exit )" ]; then
#    echo "OK!"
#else
#    echo "Fail! \n"
#fi;

if [ "$(echo "ls && exit" | ./template)" = "$( ls && exit )" ]; then
    echo "OK!"
else
    echo "Fail! ls"
fi;


if [ "$(echo "echo a && exit" | ./template)" = "$( echo a && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a"
fi;

if [ "$(echo "echo a b c && exit" | ./template)" = "$( echo a b c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! "
fi;

if [ "$(echo "yolo && exit" | ./template)" = "$( yolo && exit )" ]; then
    echo "OK!"
else
    echo "Fail! yolo"
fi;

if [ "$(echo "r5(ls) && exit" | ./template)" = "$( r5lslsls && exit )" ]; then
    echo "OK!"
else
    echo "Fail! r5(ls)"
fi;

if [ "$(echo "f5(ls) && exit" | ./template)" = "$( f5lslsls && exit )" ]; then
    echo "OK!"
else
    echo "Fail! f5(ls)"
fi;

if [ "$(echo "r5(yolo) && exit" | ./template)" = "$( r5yoloyoloyolo && exit )" ]; then
    echo "OK!"
else
    echo "Fail! r5(yolo)"
fi;

if [ "$(echo "f5(yolo) && exit" | ./template)" = "$( f5yoloyoloyolo && exit )" ]; then
    echo "OK!"
else
    echo "Fail! f5(yolo)"
fi;

if [ "$(echo "ls && ls && exit" | ./template)" = "$( ls && ls && exit )" ]; then
    echo "OK!"
else
    echo "Fail! ls && ls"
fi;

if [ "$(echo "ls && yolo && exit" | ./template)" = "$( ls && yolo && exit )" ]; then
    echo "OK!"
else
    echo "Fail! ls && yolo"
fi;

if [ "$(echo "yolo && ls && exit" | ./template)" = "$( yolo && ls && exit )" ]; then
    echo "OK!"
else
    echo "Fail! yolo && ls"
fi;

if [ "$(echo "ls || ls && exit" | ./template)" = "$( ls || ls && exit )" ]; then
    echo "OK!"
else
    echo "Fail! ls || ls"
fi;

if [ "$(echo "ls || yolo && exit" | ./template)" = "$( ls || yolo && exit )" ]; then
    echo "OK!"
else
    echo "Fail! ls || yolo"
fi;

if [ "$(echo "yolo || ls && exit" | ./template)" = "$( yolo || ls && exit )" ]; then
    echo "OK!"
else
    echo "Fail! yolo || ls"
fi;

if [ "$(echo "r3(ls) && echo a b c && exit" | ./template)" = "$( ls && ls && ls && echo a b c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! r3(ls) && echo a b c"
fi;

if [ "$(echo "r3(yolo) && echo a b c && exit" | ./template)" = "$( yolo || yolo || yolo && echo a b c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! r3(yolo) && echo a b c"
fi;

if [ "$(echo "r3(yolo) || echo a b c && exit" | ./template)" = "$( yolo || yolo || yolo || echo a b c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! r3(yolo) || echo a b c"
fi;

if [ "$(echo "f5(yolo) || echo a b c && exit" | ./template)" = "$( echo a b c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! "
fi;

if [ "$(echo "echo a b c && r5(yolo) && exit" | ./template)" = "$( echo a b c && r5yoloyoloyolo && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a b c && r5(yolo)"
fi;

if [ "$(echo "echo a b c || r3(ls) && exit" | ./template)" = "$( echo a b c || r3lslsls && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a b c || r5(ls)"
fi;

if [ "$(echo "yolo || r5(allo) && exit" | ./template)" = "$( yolo || r5alloalloallo && exit )" ]; then
    echo "OK!"
else
    echo "Fail! yolo || r5(allo)"
fi;

if [ "$(echo "yolo && r5(echo a) && exit" | ./template)" = "$( yolo && r5echoaecho aechoa && exit )" ]; then
    echo "OK!"
else
    echo "Fail! yolo && r5(echo a)"
fi;

if [ "$(echo "echo a || echo b && echo c && exit" | ./template)" = "$( echo a || echo b && echo c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! "
fi;

if [ "$(echo "echo a || echo b || echo c && exit" | ./template)" = "$( echo a || echo b || echo c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! "
fi;

if [ "$(echo "echo a && echo b && echo c && exit" | ./template)" = "$( echo a && echo b && echo c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a && echo b && echo c"
fi;

if [ "$(echo "echo a && echo b || echo c && exit" | ./template)" = "$( echo a && echo b || echo c && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a && echo b || echo c"
fi;

if [ "$(echo "echo a && echo b && echo c && echo d && exit" | ./template)" = "$( echo a && echo b && echo c && echo d && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a && echo b && echo c && echo d"
fi;

if [ "$(echo "echo a && echo b && echo c || echo d && exit" | ./template)" = "$( echo a && echo b && echo c || echo d && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a && echo b && echo c || echo d"
fi;

if [ "$(echo "echo a && echo b || echo c && echo d && exit" | ./template)" = "$( echo a && echo b || echo c && echo d && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a && echo b || echo c && echo d"
fi;

if [ "$(echo "echo a && echo b || echo c || echo d && exit" | ./template)" = "$( echo a && echo b || echo c || echo d && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a && echo b || echo c || echo d"
fi;

if [ "$(echo "echo a || echo b && echo c && echo d && exit" | ./template)" = "$( echo a || echo b && echo c && echo d && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a || echo b && echo c && echo d"
fi;

if [ "$(echo "echo a || echo b && echo c || echo d && exit" | ./template)" = "$( echo a || echo b && echo c || echo d && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a || echo b && echo c || echo d"
fi;

if [ "$(echo "echo a || echo b || echo c && echo d && exit" | ./template)" = "$( echo a || echo b || echo c && echo d && exit )" ]; then
    echo "OK!"
else
    echo "Fail! "
fi;

if [ "$(echo "echo a || echo b || echo c || echo d && exit" | ./template)" = "$( echo a || echo b || echo c || echo d && exit )" ]; then
    echo "OK!"
else
    echo "Fail! echo a || echo b || echo c || echo d"
fi;

if [ "$(echo "sleep 5 && echo a \n echo b && exit" | ./template)" = "$( sleep 5 && echo a \n echo b&& exit )" ]; then
    echo "OK!"
else
    echo "Fail! sleep 5 && echo a \n echo b"
fi;


if [ "$(echo "sleep 5 && echo a& \n echo b && exit" | ./template)" = "$( sleep 5 && echo a& \n echo b && exit )" ]; then
    echo "OK!"
else
    echo "Fail! sleep 5 && echo a& \n echo b"
fi;