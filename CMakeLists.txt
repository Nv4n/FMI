cmake_minimum_required(VERSION 3.22)
project(Restaurant)
project(Ticket)
project(ImageEditor)
project(HW02)

set(CMAKE_CXX_STANDARD 14)

include_directories(Course1/OOP-Sem2/Week14)

add_executable(Restaurant
        Course1/OOP-Sem2/Week14/BBQ/main.cpp
        Course1/OOP-Sem2/Week14/BBQ/Queue.inl
        Course1/OOP-Sem2/Week14/BBQ/Queue.h
        Course1/OOP-Sem2/Week14/BBQ/Order.h
        Course1/OOP-Sem2/Week14/HW02/InputControl.cpp Course1/OOP-Sem2/Week14/HW02/InputControl.h)

add_executable(Ticket
        Course1/OOP-Sem2/Week14/TicketSystem/main.cpp
        Course1/OOP-Sem2/Week14/TicketSystem/Ticket.h
        Course1/OOP-Sem2/Week14/TicketSystem/StudentTicket.h
        Course1/OOP-Sem2/Week14/TicketSystem/RegularTicket.h
        Course1/OOP-Sem2/Week14/TicketSystem/GroupTicket.h
        )

add_executable(ImageEditor
        Course1/OOP-Sem2/Week14/ImageEditor/main.cpp
        )

add_executable(HW02
        Course1/OOP-Sem2/Week14/HW02/main.cpp
        Course1/OOP-Sem2/Week14/HW02/Form.cpp Course1/OOP-Sem2/Week14/HW02/Form.h Course1/OOP-Sem2/Week14/HW02/Control.cpp Course1/OOP-Sem2/Week14/HW02/Control.h
        Course1/OOP-Sem2/Week14/HW02/Control.cpp Course1/OOP-Sem2/Week14/HW02/Control.h
        Course1/OOP-Sem2/Week14/HW02/InputControl.cpp Course1/OOP-Sem2/Week14/HW02/InputControl.h Course1/OOP-Sem2/Week14/HW02/OutputControl.cpp Course1/OOP-Sem2/Week14/HW02/OutputControl.h Course1/OOP-Sem2/Week14/HW02/IOControl.cpp Course1/OOP-Sem2/Week14/HW02/IOControl.h)