resource "aws_security_group" "multi_container_sg" {
  name = var.security_group_name

  tags = {
    Name = var.security_group_name
  }
}

resource "aws_vpc_security_group_ingress_rule" "ingress_port_rules" {
  security_group_id = aws_security_group.multi_container_sg.id

  for_each    = var.ingress_port_rules
  cidr_ipv4   = "0.0.0.0/0"
  from_port   = each.value
  to_port     = each.value
  ip_protocol = "tcp"
}

resource "aws_vpc_security_group_egress_rule" "egress_port_rules" {
  security_group_id = aws_security_group.multi_container_sg.id

  cidr_ipv4   = "0.0.0.0/0"
  ip_protocol = "-1"
}