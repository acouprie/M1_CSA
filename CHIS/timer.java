/** In the variable of the class **/
private Timer timerInc;


/** In the initialization part **/

// Timer declaration in the initialization
timerInc = new Timer(1000, new java.awt.event.ActionListener() {
    public void actionPerformed(java.awt.event.ActionEvent evt) {
        timerIncStartActionPerformed(evt);
    }
});
timerInc.stop();


/** With the other event functions **/
private void timerIncStartActionPerformed(java.awt.event.ActionEvent evt) {
	// To do
}