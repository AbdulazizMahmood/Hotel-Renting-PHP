<?php

require 'Booking.inc';

class room {

    private $number;
    private $type;
    private $price;
    private $status;
    private $book_id;
    private $db;

    public function __construct() {
        $this->db = new DatabaseConnect();
    }

    public function getNumber() {
        return $this->number;
    }

    public function getType() {
        return $this->type;
    }

    public function getPrice() {
        return $this->price;
    }

    public function getStatus() {
        return $this->status;
    }

    public function getBook_id() {
        return $this->book_id;
    }

    public function setNumber($number) {
        $this->number = $number;
    }

    public function setType($type) {
        $this->type = $type;
    }

    public function setPrice($price) {
        $this->price = $price;
    }

    public function setStatus($status) {
        $this->status = $status;
    }

    public function setBook_id($book_id) {
        $this->book_id = $book_id;
    }

    public function add($type, $price) {
        $this->db->Connect();
        $query = "INSERT INTO room (type,price)  VALUES( '$type' , '$price' )";
        $result = mysqli_query($this->db->getconnect(), $query);
        if (!$result) {
            die("ERR");
        } else {
            echo 'DONE Adding';
        }
        $this->db->disconnect();
    }

    public function update($number, $type, $price) {
        $this->db->Connect();
        $query = "UPDATE  room SET type='$type', price='$price' WHERE number='$number'";
        $result = mysqli_query($this->db->getconnect(),$query);
        if (!$result) {
            die("ERR");
        } else {
            echo 'DONE';
        }
        $this->db->disconnect();
    }
    public function search($number) {
        $this->db->Connect();
        $query = "SELECT * FROM room WHERE number='$number'";
        $result = mysqli_query($this->db->getconnect(), $query);
        if (!$result) {
            die("ERR");
        } else {
            echo 'Search Found' . '<br>';
            $row = mysqli_fetch_assoc($result);
            return $row;
        }
        $this->db->disconnect();
    }

    public function delete($number) {
        $this->db->Connect();
        $query = "DELETE FROM room WHERE number='$number'";
        $result = mysqli_query($this->db->getconnect(), $query);
        if (!$result) {
            die("ERR");
        } else {
            echo 'DONE Deletion';
        }
        $this->db->disconnect();
    }

}

?>
