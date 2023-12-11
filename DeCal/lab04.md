### Lab 4 - Processes and Services

<b>Question 1</b>: What is the name of a systemd service running on your system? What does it do? (If you’re not sure what it does, Google it!)

The table are services of systemd
```sh
  systemd-journal-flush.service        loaded active exited  Flush Journal to Persistent Storage
  systemd-journald.service             loaded active running Journal Service
  systemd-logind.service               loaded active running Login Service
  systemd-networkd-wait-online.service loaded active exited  Wait for Network to be Configured
  systemd-networkd.service             loaded active running Network Service
  systemd-remount-fs.service           loaded active exited  Remount Root and Kernel File Systems
  systemd-resolved.service             loaded active running Network Name Resolution
  systemd-sysctl.service               loaded active exited  Apply Kernel Variables
  systemd-sysusers.service             loaded active exited  Create System Users
  systemd-tmpfiles-setup-dev.service   loaded active exited  Create Static Device Nodes in /dev
  systemd-tmpfiles-setup.service       loaded active exited  Create Volatile Files and Directories
  systemd-udev-settle.service          loaded active exited  udev Wait for Complete Device Initialization
  systemd-udev-trigger.service         loaded active exited  udev Coldplug all Devices
  systemd-udevd.service                loaded active running udev Kernel Device Manager
  systemd-update-utmp.service          loaded active exited  Update UTMP about System Boot/Shutdown
  systemd-user-sessions.service        loaded active exited  Permit User Sessions
```
<b>Question 2</b>: What is the difference between systemctl reload yourservice and systemctl restart yourservice?
* reload can refresh the service when service running
* restart can activate the service when service stopping

<b>Question 3</b>: Upload a screenshot of your browser accessing the nginx webserver at http://[yourusername].decal.xcf.sh:420. Note: If you can’t access the IPv6 site use curl localhost:420 on the VM and paste it’s contents (it should be a html page).

`Input the import of nginx to the browser search frame #such as:'localhost:80' if import is 80 `

the following question is not to solve because environment of my pc can't to start it
