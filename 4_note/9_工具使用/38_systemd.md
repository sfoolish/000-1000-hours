## systemd service configure

/etc/systemd/system
/lib/systemd/system/glance-api.service
systemctl daemon-reload

service glance-api status

https://www.digitalocean.com/community/tutorials/understanding-systemd-units-and-unit-files
https://www.digitalocean.com/community/tutorials/how-to-use-systemctl-to-manage-systemd-services-and-units
https://www.freedesktop.org/software/systemd/man/systemd.service.html
http://lists.clusterlabs.org/pipermail/users/2015-August/000956.html
https://jira.opnfv.org/projects/COMPASS/issues/COMPASS-515


## ubuntu 16.04 insecure-registry

/etc/default/docker
DOCKER_OPTS="--insecure-registry 192.168.122.11:4000"

cp /lib/systemd/system/docker.service /etc/systemd/system/docker.service

vim /etc/systemd/system/docker.service
[Service]
EnvironmentFile=-/etc/default/docker
ExecStart=/usr/bin/docker daemon -H fd:// $DOCKER_OPTS
