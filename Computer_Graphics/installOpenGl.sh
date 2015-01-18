echo "I don't guarantee that this will get the job done."
echo "This might screw your OS or blow up your house."

read -p "You wanna take the risk?? Y/N" RESP
if [ "$RESP" = "y" ] || [ "$RESP" = "Y" ]; then
    printf "Installing packages\n\n"
    sudo apt-get install build-essential
    sudo apt-get install freeglut3-dbg freeglut3
    sudo apt-get install libglewmx-dev glew-utils libgle3-dbg libglewmx-dbg libglew-dev libglewmx1.10 libglew1.10
    

    printf "Copying Files.\n\n"
    sudo cp /usr/lib/x86_64-linux-gnu/libglut.a /usr/lib/
    sudo cp /usr/lib/x86_64-linux-gnu/libglut.so /usr/lib/
    sudo cp /usr/lib/x86_64-linux-gnu/libglut.so.3 /usr/lib/
    sudo cp /usr/lib/x86_64-linux-gnu/libglut.so.3.9.0 /usr/lib/
    
    printf "Changing permissions.\n\n"
    cd /usr/lib
    sudo chown $USER:$USER libglut.*

    printf "\n\nNow be a bit SMARTASS and setup CodeBlocks yourself\n"
    echo "Thanks"
    
else
    printf "\nThanks for not trusting me ;)\n"
fi
