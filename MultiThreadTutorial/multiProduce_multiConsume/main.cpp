#include <iostream>
#include <unistd.h>
#include <condition_variable>
#include <mutex>
#include <thread>

using namespace std;

static const int kItemRepositorySize = 4;
static const int kItemsToProduce = 10;

struct ItemRepository
{
    int item_buffer[kItemRepositorySize];
    size_t read_position;
    size_t write_position;
    size_t produced_item_counter;
    size_t consumed_item_counter;
    mutex mtx;
    mutex produced_item_counter_mtx;
    mutex consumed_item_counter_mtx;
    condition_variable repo_not_full;
    condition_variable repo_not_empty;
} gItemRepository;  //gItemRepository 就相当于声明实例化一个全局的ItemRepository结构体对象

//typedef struct ItemRepository ItemRepository;

void produceItem(ItemRepository* ir, int item)
{
    unique_lock<mutex> lock(ir->mtx);
    while (((ir->write_position+1) % kItemRepositorySize) == ir->read_position)
    {
        cout << "Producer is waiting for an empty slot..." << endl;
        ir->repo_not_full.wait(lock);
    }
    ir->item_buffer[ir->write_position] = item;
    ++ir->write_position;
    if (ir->write_position == kItemRepositorySize)
        ir->write_position = 0;
    ir->repo_not_empty.notify_all();
    lock.unlock();
}

void producerTask()
{
    bool produce_exit = false;
    while (1)
    {
        //sleep(1);
        unique_lock<mutex> lock(gItemRepository.produced_item_counter_mtx);
        if (gItemRepository.produced_item_counter < kItemsToProduce)
        {
            ++gItemRepository.produced_item_counter;
            produceItem(&gItemRepository, gItemRepository.produced_item_counter);
            cout << "Producer thread " << this_thread::get_id() << " is producing the " << gItemRepository.produced_item_counter << "^th item" << endl;
        }
        else
        {
            produce_exit = true;
        }
        lock.unlock();
        if (produce_exit == true)
            break;
    }
    cout << "Producer thread " << this_thread::get_id() << " is exiting..." << endl;
}

int consumeItem(ItemRepository* ir)
{
    int data;
    unique_lock<mutex> lock(ir->mtx);
    while (ir->write_position == ir->read_position)
    {
        cout << "Consumer is waiting for items..." << endl;
        ir->repo_not_empty.wait(lock);
    }
    data = ir->item_buffer[ir->read_position];
    ++ir->read_position;
    if (ir->read_position >= kItemRepositorySize)
        ir->read_position = 0;
    ir->repo_not_full.notify_all();
    lock.unlock();
    return data;
}

void consumerTask()
{
    bool consume_exit;
    while (1)
    {
        //sleep(1);
        unique_lock<mutex> lock(gItemRepository.consumed_item_counter_mtx);
        if (gItemRepository.consumed_item_counter < kItemsToProduce)
        {
            int item = consumeItem(&gItemRepository);
            ++gItemRepository.consumed_item_counter;
            cout << "Consumer thread " << this_thread::get_id() << " is consuming the " << item << "^th item" << endl;
        }
        else
        {
            consume_exit = true;
        }
        lock.unlock();
        if (consume_exit == true)
            break;
    }
    cout << "consumer thread " << this_thread::get_id() << " is exiting..." << endl;
}

void initItemRepository(ItemRepository* ir)
{
    ir->write_position = 0;
    ir->read_position = 0;
    ir->produced_item_counter = 0;
    ir->consumed_item_counter = 0;
}

int main()
{
    initItemRepository(&gItemRepository);
    thread consumer1(consumerTask);
    thread consumer2(consumerTask);
    thread consumer3(consumerTask);
    thread consumer4(consumerTask);
    thread producer1(producerTask);
    thread producer2(producerTask);
    thread producer3(producerTask);
    thread producer4(producerTask);
    consumer1.join();
    consumer2.join();
    consumer3.join();
    consumer4.join();
    producer1.join();
    producer2.join();
    producer3.join();
    producer4.join();
    return 0;
}
