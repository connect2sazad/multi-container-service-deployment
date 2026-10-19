import express from 'express';
import conn from './db.js';
import { ObjectId } from 'mongodb';

const router = express.Router();

// health & readiness
router.get('/', async (req, res, next) => {
    try {
        const todos = await conn;
        await todos.db.command({ ping: 1 });

        res.status(200).json({
            health: 'Healthy',
            status: "up",
            database: 'connected'
        });
    } catch (error) {
        res.status(503).json({
            health: 'Unhealthy',
            status: 'down',
            database: 'disconnected',
        });
    }
});

// create todo
router.post('/todos', async (req, res, next) => {
    try {
        const todos = await conn;
        const result = await todos.insertOne(req.body);

        res.status(201).json({
            message: 'todo created successfully',
            data: result,
        });
    } catch (error) {
        res.status(500).json({ error: 'Failed to create todo', details: error.message });
    }
});

// get all todos
router.get('/todos', async (req, res, next) => {
    try {
        const todos = await conn;
        const result = await todos.find({}).toArray();

        res.status(200).json({
            message: 'todos fetched successfully',
            data: result,
        });
    } catch (error) {
        res.status(500).json({ error: 'Failed to fetch todos', details: error.message });
    }
});

// get a single todo
router.get('/todos/:id', async (req, res, next) => {
    try {
        const todos = await conn;
        const { id } = req.params;

        if (!ObjectId.isValid(id)){
            return res.status(400).json({
                error: 'Invalid Todo ID'
            });
        }

        const todo = await todos.findOne({
            _id: new ObjectId(id),
        });

        if(!todo){
            return res.status(404).json({
                error: 'Todo Not Found'
            });
        }



        res.status(200).json({
            message: 'Todo fetched successfully',
            data: todo,
        });
    } catch (error) {
        res.status(500).json({ error: 'Failed to fetch Todo', details: error.message });
    }
});


const routes = router;
export default routes;