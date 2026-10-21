variable "region" {
  type = string
}

variable "security_group_name" {
  type = string
}

variable "ingress_port_rules" {
  type = map(number)
}

variable "ami_image_owners" {
  type = list(string)
}

variable "ami_image_name" {
  type = list(string)
}

variable "root_device_type" {
  type = list(string)
}

variable "virtualization_type" {
  type = list(string)
}

variable "instance_type" {
  type = string
}

variable "deployment_server_name" {
  type = string
}