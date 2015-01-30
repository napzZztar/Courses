echo "I don't guarantee that this will get the job done."
echo "This might screw your OS or blow up your house."

read -p "You wanna take the risk?? Y/N" RESP
if [ "$RESP" = "y" ] || [ "$RESP" = "Y" ]; then
    printf "Installing packages\n\n"
    sudo apt-get install -y build-essential
    sudo apt-get install -y freeglut3-dbg freeglut3
    sudo apt-get install -y libglewmx-dev glew-utils libgle3-dbg libglewmx-dbg libglew-dev libglewmx1.10 libglew1.10
    

    printf "Copying Files.\n\n"
    sudo cp /usr/lib/x86_64-linux-gnu/libglut.a /usr/lib/
    sudo cp /usr/lib/x86_64-linux-gnu/libglut.so /usr/lib/
    sudo cp /usr/lib/x86_64-linux-gnu/libglut.so.3 /usr/lib/
    sudo cp /usr/lib/x86_64-linux-gnu/libglut.so.3.9.0 /usr/lib/
    
    printf "Changing permissions.\n\n"
    cd /usr/lib
    sudo chown $USER:$USER libglut.*

    read -p "Do you want to coy the GLU files too? Y/N" RESP1
    if [ "$RESP1" = "y" ] || [ "$RESP1" = "Y" ]; then
        sudo cp /usr/lib/x86_64-linux-gnu/libGLU.a /usr/lib/
        sudo cp /usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/
        sudo cp /usr/lib/x86_64-linux-gnu/libGLU.so.1 /usr/lib/
        sudo cp /usr/lib/x86_64-linux-gnu/libGLU.so.1.3.1 /usr/lib/
        sudo chown $USER:$USER libGLU.*
    fi


    printf "\n\nNow be a bit SMARTASS and setup CodeBlocks yourself\n"
    echo "Thanks"
    
else
    printf "\nThanks for not trusting me ;)\n"
fi
