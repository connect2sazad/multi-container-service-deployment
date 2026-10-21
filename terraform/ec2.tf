resource "aws_instance" "deployment_server" {

 ami = data.aws_ami.server_ami.id
 instance_type = var.instance_type

#  key_name = 

associate_public_ip_address = true

tags = {
  Name = var.deployment_server_name
}

}