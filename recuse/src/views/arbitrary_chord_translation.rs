use crate::shared::distributed_user_data::{DistributedHashTable, FingerTable, ArbitraryNodeNetwork};

fn main() {
    let vector_matrix: [[u32; 2]; 10] = [
        [1, 0],
        [2, 85],
        [3, 133],
        [4, 182],
        [5, 210],
        [6, 245],
        [7, 279],
        [8, 324],
        [9, 395],
        [10, 451],
    ];
    let array_keys: [u32; 10] = [0, 85, 133, 182, 210, 245, 279, 324, 395, 451];
    let dht = DistributedHashTable {
        predecessor: 0,
        successor: 1,
        hashkey: 85,
        size: 10,
    };
    let finger = FingerTable {
        interval_matrix: vector_matrix,
        keys: array_keys,
        dht,
    };

    finger.starting_node();
    let predecessor = finger.find_predecessor(1);
    let successor = finger.find_successor(0);
    finger.closest_preceding_finger(successor);
    let interval = finger.interval();

    loop {
        <FingerTable as ArbitraryNodeNetwork>::join(finger);
        <FingerTable as ArbitraryNodeNetwork>::update_finger_table(
            finger,
            successor,
            predecessor,
        );
        <FingerTable as ArbitraryNodeNetwork>::check_predecessor(finger);
        <FingerTable as ArbitraryNodeNetwork>::notify(finger, interval);
        <FingerTable as ArbitraryNodeNetwork>::stabilize(finger);
        <FingerTable as ArbitraryNodeNetwork>::fix_fingers(finger);
    }
}