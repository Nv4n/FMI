import * as path from 'node:path';
import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

export default defineConfig({
    plugins: [react()],
    resolve: {
        alias: {
            '@scripts': path.resolve(__dirname, './scripts'),
        }
    },
});
