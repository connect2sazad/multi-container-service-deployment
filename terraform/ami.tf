data "aws_ami" "server_ami" {

  most_recent = true
  owners      = var.ami_image_owners

  filter {
    name = "name"
    values = var.ami_image_name
  }

  filter {
    name = "root-device-type"
    values = var.root_device_type
  }

  filter {
    name = "virtualization-type"
    values = var.virtualization_type
  }

}
