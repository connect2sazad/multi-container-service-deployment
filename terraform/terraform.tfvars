region              = "ap-south-1"
security_group_name = "multi-container-sg"
ingress_port_rules = {
  http  = 80
  https = 443
}
ami_image_owners = ["099720109477"]
ami_image_name=["ubuntu/images/hvm-ssd-gp3/ubuntu-resolute-26.04-amd64-server-*"]
root_device_type=["ebs"]
virtualization_type=["hvm"]
instance_type="t3.micro"
deployment_server_name="Deployment Server"